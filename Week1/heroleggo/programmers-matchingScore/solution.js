// page html 의 <meta property="og:url" content="https://asdasd.com"/>
// 을 찾아 https://asdasd.com 의 형태로 반환하는 함수
const getOrigin = (page) => {
    const data = page.trim().split('<'); // 공백 제거 후 < 기준 데이터 split (html의 <은 tag에만 쓰이기 때문)
    const content = data.find(d => d.includes('meta property="og:url"')); // 하나밖에 없는 이것 찾기
    return content.split('"').find((d) => d.startsWith('https://')); // "을 기준으로 나눈 후 https://로 시작하는 형태 반환
}

// page html의 <a href="https://link.com"> asd </a>의 형태에서
// https://link.com 을 모두 찾아 배열로 반환하는 함수
const getLinks = (page) => {
    const data = page.trim().split('<'); // 위와 같음
    const links = [];
    data.forEach((d) => {
        if (d.includes('a href="https:')) { // 로직도 위와 같음
            links.push(d.split('"').find((txt) => txt.startsWith('https://')));
        }
    })
    
    return links;
}

// 전체 페이지에서 word와 동일한 형태의 문자 수 반환
const getWordCount = (page, word) => {
    const data = page.trim().toUpperCase().split(/[^a-zA-Z]/); // 모두 대문자로 바꿔줌
    
    let count = 0;

    data.forEach((d) => {
        if (word.toUpperCase() === d) { // word도 대문자로 바꾸기 때문에 카운트가 가능
            count++;
        }
    })
    
    return count;
}


const solution = (word, pages) => {
    // 사용하기 좋은 형태로 데이터 변환 (origin, wordCount, links, linkScore, matchingScore, index 포함하도록)
    const parsedData = pages.map((page, index) => {
        return {
            origin: getOrigin(page),
            wordCount: getWordCount(page, word),
            links: getLinks(page),
            linkScore: 0,
            matchingScore: 0,
            index,
        };
    });
    
    // linkScore 계산
    parsedData.forEach((data) => {
        let linkScore = 0;
        data.links.forEach((link) => {
            const d = parsedData.find((i) => i.origin === link); // 다른 링크가 리스트에 있는지 체크
            if (d !== undefined) { // 있으면 해당 링크의 링크 점수 업데이트
                d.linkScore += (data.wordCount / data.links.length);
            }
        });
    });

    // 기본점수 + 링크점수로 매칭점수 계산
    parsedData.forEach((data) => {
        data.matchingScore = data.wordCount + data.linkScore;
    })
    
    // 매칭점수 내림차순, 인덱스 오름차순으로 정렬
    parsedData.sort((a, b) => {
        if (a.matchingScore === b.matchingScore) {
            return a.index - b.index;
        }
        return b.matchingScore - a.matchingScore;
    })

    // 첫 번째 인덱스 반환
    return parsedData[0].index;
}