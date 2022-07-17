import re
# 정규표현식으로 모든 태그를 찾아서 반환하는 함수 : list
def TagParser(contents):
    pattern = '(<([^>]+)>)'
    find_all_tags = re.findall(pattern, contents)

    return find_all_tags

# 태그 사이에 있는 텍스트만 가져오는 함수 : string
def getText(contents):
    tags = TagParser(contents)

    for tag in tags:
        contents = contents.replace(tag[0], '')
    innerHtmlContents = contents.replace('\n', '')

    return innerHtmlContents

# 텍스트에서 해당하는 단어만 검색한 후 갯수를 반환하는 함수
# getText()로 얻은 값을 입력으로 받음
def searchWord(word, innerHtmlContents):
    word = word.lower()
    pattern = '[a-z]+'
    find_all_txt = re.findall(pattern, innerHtmlContents.lower())
    count = 0
    for txt in find_all_txt:
        if txt.find(word) != -1: # Comment : 이걸로 하면 95점
            count += 1
        # if txt == word: # Comment : 이걸로 하면 80점
        #     count += 1
    return count

# meta 태그 안에 content에 담긴 url을 가져옴
def getUrl(contents):
    tags = TagParser(contents)
    for tag, _ in tags:
        if tag.find("<meta") != -1:
            try:
                url = tag.split('content="')[1].split('"')[0]
                break
            except:
                pass
    return url

class Page():
    def __init__(self, word, contents):
        self.word = word
        self.contents = contents
        self.url = getUrl(contents) # url
        self.basic_score = searchWord(word,  getText(contents)) # 기본 점수
        self.ext_link_num = 0 # 외부 링크 수
        self.ext_link_list = [] # 외부 링크 리스트 (어디를 가리키는지)
        self.link_score = [] # 링크 점수
        self.match_score = 0 # 매칭 점수
        
        self.ext_link_num = self.ext_link()

    def ext_link(self):
        href = self.contents.split('<a href="')
        for a_tag in href[1:]:
            self.ext_link_list.append(a_tag.split('"')[0])
        return len(href) - 1

    def set_link_score(self, page_copy):
        self.link_score.append(page_copy.basic_score / page_copy.ext_link_num)

    def get_link_score(self):
        return sum(self.link_score)

    def get_match_score(self):
        self.match_score = self.basic_score + self.get_link_score()
        return self.match_score

def solution(word, pages):
    answer = 0
    page_obj_list = [Page(word, page) for page in pages]

    for page in page_obj_list:
        for other_page in page_obj_list:
            if page == other_page:
                continue
            if page.url in other_page.ext_link_list:
                page.set_link_score(other_page)

    scores = []
    for page in page_obj_list:
        scores.append(page.get_match_score())

    return scores.index(max(scores))