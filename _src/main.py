import os
import time
import sys
from datetime import datetime

import get
import fetch
from commit import commit, commitAll


def main():
    # sys.argv : コマンドライン引数
    # => github action で crawl_all.yml を用いてコンテナが起動された際の条件分岐 
    fetchall = (len(sys.argv) > 1 and sys.argv[1] == 'fetch_all')
    if fetchall:
        with open("_src/lastFetchedAll.txt", "r") as f:
            sec = int(f.read()) + 1
    else:
        sec = get.last_submission_epoch()
    print("Last Submission Time:", datetime.fromtimestamp(sec))

    submissions = fetch.submissions(sec)

    print("Found {} submission(s)".format(len(submissions)))

    # 前回取得時以降、新submissionが無ければ何もしない
    if len(submissions) == 0:
        print("No new submissions")
        return

    cnt = 1
    for s in submissions:
        print(f"\r\033[1m ({cnt: 3}/{len(submissions): 3})\033[0m Submission #{s.id} ({s.problem_id}, at {datetime.fromtimestamp(s.epoch_second)})", end="", flush=True)
        time.sleep(2)
        save_dir = os.path.join(os.path.dirname(__file__), "..", s.contest_id)
        save_path = f"{save_dir}{os.sep}{s.problem_id}_{s.id}_{s.result}.{get.extension(s.language)}"

        os.makedirs(save_dir, exist_ok=True)
        with open(save_path, mode="w", encoding="UTF-8") as file:
            # submission ファイルに情報付加
            file.write("/*\n")
            file.write(f" * Author: {s.user_id}\n")
            file.write(f" * Submission URL: {get.submission_url(s)}\n")
            file.write(f" * Submitted at: {datetime.fromtimestamp(s.epoch_second)}\n")
            file.write(f" * Problem URL: {get.problem_url(s)}\n")
            file.write(f" * Result: {s.result}\n")
            file.write(f" * Execution Time: {s.execution_time} ms\n")
            file.write(" */\n\n")
            file.write(fetch.code(s))
        if not fetchall:
            commit(s, save_path)
        cnt += 1

    if fetchall:
        with open("_src/lastFetchedAll.txt", "w") as f:
            f.write(str(submissions[-1].epoch_second))
        commitAll()
    print("All Done!")


if __name__ == "__main__":
    main()