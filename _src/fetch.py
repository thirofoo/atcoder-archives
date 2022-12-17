import time
import requests
from bs4 import BeautifulSoup

from datatypes import Submission
import get


# epoch_sec (1970年1月1日午前0時0分0秒（UTC）からの経過秒数) を指定してsubmissionを取得
def submissions(epoch_sec: int) -> list:
    url = f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=through&from_second={epoch_sec}"
    res = requests.get(url).json()
    return [Submission(**s) for s in res]


# 全submissionを取得
def allSubmissions() -> list:
    nowsec = 0
    res = []
    while True:
        url = f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=through&from_second={nowsec}"
        now = requests.get(url).json()
        if len(now) == 0:
            break
        res += [Submission(**s) for s in now]
        nowsec = res[-1].epoch_second + 1
        time.sleep(1)
    return res


def code(s: Submission) -> str:
    url = get.submission_url(s)
    res = requests.get(url).text
    soup = BeautifulSoup(res, "html.parser")
    code = soup.select_one("pre#submission-code")
    if code is None:
        print("code not found for", s.id)
        return "// code not found"
    return code.text.replace("\r", "")
