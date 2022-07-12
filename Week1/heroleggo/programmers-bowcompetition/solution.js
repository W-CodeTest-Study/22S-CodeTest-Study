const solution = (n, info) => {
    // index를 활용하기 위해 reverse -> 0점 ~ 10점 -> score[0] ~ score[10]
    let ryanInfo = Array(11).fill(0);
    let max = 0;
    
    // 한 발을 쏘는 함수 (재귀형태로 구성)
    // 함수를 읽으면 알 수 있지만, 맨 뒤 (0점) 부터 채워서 값들을 테스트하는 형태로 구성되어 있음
    const shot = (apeach, ryan, count, index, board) => {
        if (n < count) { // 쏜 카운트가 제시된 n보다 높을 경우 함수 종료
            return;
        }
        if (index > 10) { // 10점까지 모두 쏘았을 경우 종료
            const scoreDiff = ryan - apeach;
            
            // max가 바뀌어 ryanInfo를 수정해야 할 경우 수정
            if (max < scoreDiff) {
                board[10] = n - count; // 0점에 남은거 때려박기
                max = scoreDiff; // max 변경
                ryanInfo = board; // 라이언의 현황 업데이트
            }
            return;
        }
        
        if (n > count) { // 횟수가 기준보다 낮을 경우
            let current = [...board]; // 새 변수에 기존 점수판 할당
            current[10 - index] = info[10 - index] + 1; // 현재 인덱스의 값을 어피치의 인덱스의 값 + 1로 변경
            shot(apeach, ryan + index, count + info[10 - index] + 1, index + 1, current); // 카운트를 더한 값, 인덱스를 더한 값을 변경하고, 변경한 점수판까지 재귀함수에 전달
        }
        
        if (info[10 - index] > 0) { // 어피치가 저기다 한발이라도 쐈을 때
            shot(apeach + index, ryan, count, index + 1, board); // 어피치의 점수 높이고, 인덱스 증가
        } else {
            shot(apeach, ryan, count, index + 1, board); // 아닐 경우 그냥 인덱스 증가
        }
    };
    
    shot(0, 0, 0, 0, ryanInfo);

    return max <= 0 ? [-1] : ryanInfo;
}