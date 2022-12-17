import os
import json
import git

from datatypes import Submission

with open(os.path.join(os.path.dirname(__file__), "ext.json"), mode="r", encoding="UTF-8") as file:
    extensions = json.load(file)


def extension(lang: str) -> str:
    for v in extensions:
        if lang.startswith(v):
            return extensions[v]
    return "unknown"


def submission_url(s: Submission) -> str:
    return f"https://atcoder.jp/contests/{s.contest_id}/submissions/{s.id}"


def problem_url(s: Submission) -> str:
    return f"https://atcoder.jp/contests/{s.contest_id}/tasks/{s.problem_id}"


# 最終提出のエポック秒を取得
def last_submission_epoch() -> int:
    repo = git.Repo(".")
    if not repo.active_branch.is_valid():
        return 0

    for commit in repo.iter_commits():
        try:
            # 過去の commit message にあるエポック秒を取得
            # ※ 空白区切りで sprit すると 最後の文字列が (epoch) になってる (今のところ)
            epoch_sec = int(commit.message.split(" ")[-1].replace("(", "").replace(")", "")) + 1
            print("Found Last Submission Commit:", commit.message)
            return epoch_sec
        except ValueError as err:
            print(f"ValueError ({err})", commit.message)
            continue
        except IndexError as err:
            print(f"IndexError ({err})", commit.message)
            continue
    return 0