import os
import sys
from bs4 import BeautifulSoup


valid_ojs = ['codeforces', 'kattis', 'leetcode']
ojs_by_first = {'c': 'codeforces', 'k': 'kattis', 'l': 'leetcode'}
working_dir = os.path.realpath(os.getcwd())
script_dir = os.path.realpath(__file__)
root_dir = os.path.join(script_dir, os.pardir, os.pardir)

sys.path.append(root_dir)

help_prompt = '(help prompt not set yet)'


def enforce_arg_cnt(lower=None, upper=None):
    if lower is not None and len(sys.argv) < lower:
        print('Not enough arguments!', help_prompt, sep='\n')
        exit(1)
    if upper is not None and len(sys.argv) > upper:
        print('Too many arguments!', help_prompt, sep='\n')
        exit(1)


def get_oj_from_dir(dir=working_dir):
    inds = {oj: dir.find(oj) for oj in valid_ojs}
    inds[None] = 0
    return max(inds, key=inds.get)


def oj_user_prompt(oj=None):
    if oj is None or oj not in ojs_by_first.keys():
        while True:
            print('Please specify OJ:')
            for k, v in ojs_by_first.items():
                print("\t[", k, "]", v[1:], sep="")
            oj = input()
            if oj in ojs_by_first.keys():
                break
    return ojs_by_first[oj]


def problem_dir(oj, problem_id):
    return os.path.join(root_dir, oj, 'problems', problem_id)


def contest_dir(oj, contest_id):
    return os.path.join(root_dir, oj, 'contests', contest_id)




