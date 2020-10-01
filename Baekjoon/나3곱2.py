class TwoThreeCnt:
    def __init__(self, index, number):
        self.index = index
        self.two = TwoThreeCnt._get_cnt(number, 2)
        self.three = TwoThreeCnt._get_cnt(number, 3)

    @staticmethod
    def _get_cnt(number, two_or_three):
        cnt = 0
        while True:
            if number == 0:
                return cnt
            if number % two_or_three != 0:
                return cnt
            cnt += 1
            number /= two_or_three


def solve(shuffled):
    parsed = [TwoThreeCnt(idx, number) for idx, number in enumerate(shuffled)]
    sort_seq = sorted(parsed, key=lambda item: (-item.three, item.two))
    return [shuffled[item.index] for item in sort_seq]


import sys

n = int(input())
inputs = list(map(int, input().split()))
answer = solve([int(input) for input in inputs])
[print(ans, end=" ") for ans in answer]
