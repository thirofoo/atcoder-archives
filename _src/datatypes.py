class Submission:
    id: int
    epoch_second: int
    problem_id: str
    contest_id: str
    user_id: str
    language: str
    point: int
    length: int
    result: str
    execution_time: int

    # Submission API の全情報の型
    def __init__(self, **kwargs):
        self.id = kwargs["id"]
        self.epoch_second = kwargs["epoch_second"]
        self.problem_id = kwargs["problem_id"]
        self.contest_id = kwargs["contest_id"]
        self.user_id = kwargs["user_id"]
        self.language = kwargs["language"]
        self.point = kwargs["point"]
        self.length = kwargs["length"]
        self.result = kwargs["result"]
        self.execution_time = kwargs["execution_time"]