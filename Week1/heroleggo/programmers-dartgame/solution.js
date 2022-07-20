// 각 값의 Single, Double, Triple 여부를 판단하여 값을 곱해주는 함수
const getScore = (value) => {
    if (value.indexOf('S') !== -1) {
        return +value.match(/\d+/)[0];
    } else if (value.indexOf('D') !== -1) {
        return (+value.match(/\d+/)[0]) ** 2;
    } else if (value.indexOf('T') !== -1) {
        return (+value.match(/\d+/)[0]) ** 3;
    }
}

// 옵션 존재 여부를 체크해서 반환하는 함수
const checkOption = (value) => {
    return value.indexOf('#') !== -1 ? -1 : value.indexOf('*') !== -1 ? 1 : 0;
}

// 문자열로 들어온 데이터를 해석하여 반환하는 함수
const parseToArray = (data) => {
    const PARSE_REGEX = /\d+[S,D,T][\*,#]?/;
    let result = [];
    while(true) {
        if (data.length === 0) {
            break;
        }
        let matchResult = data.match(PARSE_REGEX);
        result.push(matchResult[0]);
        data = data.slice(matchResult[0].length);
    }
    
    return result;
}

// 데이터를 받고, 점수의 합을 계산하는 함수
const calculateScore = (data) => {
    let result = 0;
    data.forEach((value, idx) => {
        if (data[idx].option === 1) { // 스타상
            // 첫 인덱스는 앞이 없기 때문에 자신만 계산
            if (idx === 0) {
                data[idx].score *= 2;
            } else { // 이외에는 이전 점수까지 곱해줌
                data[idx].score *= 2;
                data[idx - 1].score *= 2;
            }
        } else if (data[idx].option === -1) { // 아차상
            data[idx].score *= -1;
        }
    });
    data.forEach((v) => result += v.score);
    
    return result;
}

const solution = (dartResult) => {
    const parsed = parseToArray(dartResult);
    const data = parsed.map((v) => { return { score: getScore(v), option: checkOption(v) }; });
    const answer = calculateScore(data);
    
    return answer;
}