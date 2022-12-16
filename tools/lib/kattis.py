import requests
import re
import json
from typing import Optional
from bs4 import BeautifulSoup

URL = "https://open.kattis.com/problems/"


def html_page(page):
    """
        Returns a BS object from a requests
        page.text

        :param page: request page
        """
    return BeautifulSoup(page.text, "html.parser")


# def problems(pages=1) -> dict:
#     """
#       Fetches all Kattis problems
#
#       :param pages: number of problem pages, defaults to 1
#       :rtype: list of problem objects
#       """
#     ret = []
#     for page in range(pages):
#         probs = html_page(requests.get(URL + "?page={}".format(page)))
#         for problem_id in problem_list(probs):
#             ret.append(problem(problem_id))
#     return ret


def problem(problem_id: str) -> dict:
    """
      Fetches information for a single Kattis problem

      :param problem_id: id of a Kattis problem
      :rtype: json object
      """
    obj = {
        "url": URL + problem_id,
    }

    problem_page = html_page(requests.get(obj["url"]))

    if add_problem_information(problem_page, obj) is None:
        return {}

    return obj


def add_problem_information(problem_page, problem: dict) -> None:
    """
      Parses problem information and adds it
      to problem object

      """
    fields = ["time_limit", "memory_limit", "difficulty"]

    info = problem_page.find("div", {"class": "attribute_list-book attribute_list"})
    if info is None:
        return None
    info = info.findAll("div", {"class": "attribute_list-item"})

    print(info)
    for i in range(len(info)):
        s = re.compile(r"[^\d.]+")
        info[i] = s.sub("", str(info[i]))

    problem["info"] = {fields[i]: info[i] for i in range(min(len(info), len(fields)))}



def problem_list(page):
    """
      Returns a list of problem ID's scraped from a
      Kattis contest

      :param page: contest page
      """
    problems = page.findAll("a", {"href": re.compile(r'.*problems/.*')}, recursive=True)
    if problems is None:
        return None
    for problem in problems:
        print(problem["href"].split("/")[-1])

    return [str(problems[i]).split("/")[2].split('"')[0] for i in range(0, len(problems), 3)]

