import git
from datetime import datetime

from datatypes import Submission


def commitAll() -> None:
    repo = git.Repo(".")
    repo.git.add(".")
    commit_msg = "Commit All"
    try:
        repo.git.commit("-m", commit_msg, "-S")
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[91mFail\033[0m Failed to commit: {commit_msg}", flush=True)
        print(err)
        exit(1)
    try:
        repo.git.rebase("HEAD~1", "--committer-date-is-author-date")
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[91mFail\033[0m Failed to rebase: {commit_msg}", flush=True)
        print(err)
        exit(1)
    print("\033[2K\033[G", end="")
    print(f"\r\033[92mDone\033[0m {commit_msg}", flush=True)


def commit(s: Submission, path: str) -> None:
    repo = git.Repo(".")
    repo.git.add(path)
    commit_msg = f"[{s.result}] SubmissionID: {s.id} at {datetime.fromtimestamp(s.epoch_second)} ({s.epoch_second})"
    try:
        repo.git.commit("-m", commit_msg, "-S", "--date", s.epoch_second)
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[91mFail\033[0m Failed to commit: {commit_msg}", flush=True)
        print(err)
        exit(1)
    try:
        repo.git.rebase("HEAD~1", "--committer-date-is-author-date")
    except git.GitCommandError as err:
        print("\033[2K\033[G", end="")
        print(f"\r\033[91mFail\033[0m Failed to rebase: {commit_msg}", flush=True)
        print(err)
        exit(1)
    print("\033[2K\033[G", end="")
    print(f"\r\033[92mDone\033[0m {commit_msg}", flush=True)