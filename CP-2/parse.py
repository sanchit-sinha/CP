import numpy as np
from bs4 import BeautifulSoup
import requests
import re
import time
import argparse
import os
import string
from tqdm import tqdm

parser = argparse.ArgumentParser(description='parse test cases')

parser.add_argument('--contestId', type=str, help='enter the id of the contest')
parser.add_argument('--problem', type=str, help='enter the problem', default='all')
parser.add_argument('--input_file_pref', type=str, help='enter input pref',default='in')
parser.add_argument('--output_file_pref', type=str, help='enter output pref', default='o')

args = parser.parse_args()

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    
def fetch_html(url):
    response = requests.get(url)
    return response.text

def parse_problem_list():
    if args.contestId == None:
        return ['A' , 'B', 'C']
    print("fetching problems list...")
    url_contest = 'https://codeforces.com/contest/'+args.contestId
    html2 = fetch_html(url_contest)
    soup2 = BeautifulSoup(html2, 'html.parser')
    problem_soup = soup2.find_all('td', {'class' :'id'})
    problems_list = []

    pbar = tqdm(problem_soup)
    for x in pbar:
        problems_list.append(x.text.strip())
        pbar.set_description("parsing problem %s"%(problems_list[-1]))

    print ("problem list: ", problems_list)
    return problems_list


def parse_problem(problem_name):
    print(bcolors.BOLD, '='*12, bcolors.ENDC)
    CONTEST_ID = args.contestId
    base_url = 'https://codeforces.com/contest/'+ str(CONTEST_ID) + '/problem/' + str(problem_name)
    html_document = fetch_html(base_url)
    soup = BeautifulSoup(html_document, 'html.parser')
    
    inputs = soup.find_all("div", {"class": "input"})
    outputs = soup.find_all('div', {'class': 'output'})
    
    os.makedirs(problem_name, exist_ok = True)
    
    parsed_test_cases = False
    for i, ip in enumerate(inputs):
        parsed_test_cases = True
        print(bcolors.OKGREEN, ": parsing input number %d"%(i + 1), bcolors.ENDC)

        input_text = ip.text.strip().split('\n')
        input_test_case = ('\n'.join(input_text[1:]))
        input_file_name = args.input_file_pref + "%d"%(i + 1)
        
        with open(os.path.join(problem_name, input_file_name), 'w') as handle:
            handle.write(input_test_case + "\n")
            
        
    
    for i, op in enumerate(outputs):
        parsed_test_cases = True
        print(bcolors.OKGREEN, ": parsing output number %d"%(i + 1), bcolors.ENDC)

        output_text = op.text.strip().split('\n')
        output_test_case = ('\n'.join(output_text[1:]))
        output_file_name = args.output_file_pref + "%d"%(i + 1)
        
        with open(os.path.join(problem_name, output_file_name), 'w') as handle:
            handle.write(output_test_case + "\n")
           
    if parsed_test_cases == True:
        print(bcolors.OKCYAN, bcolors.BOLD, bcolors.UNDERLINE, "Problem %s test-case parsed"%(problem_name), bcolors.ENDC)
        
    if parsed_test_cases == False:
        os.system("rm -rf " + problem_name)
    if args.problem == 'all':
        return parsed_test_cases
    
    if parsed_test_cases == False:
        print(bcolors.FAIL, bcolors.BOLD, bcolors.UNDERLINE, "Problem doesnot exist", bcolors.ENDC)
    
    return parsed_test_cases

def main():
    problem_list = parse_problem_list()
    if args.problem == 'all':
        for problem_id in problem_list:
            status = parse_problem(problem_id)
            if status == False:
                break
    else:
        parse_problem(args.problem)

    
    
if __name__ == '__main__':
    main()