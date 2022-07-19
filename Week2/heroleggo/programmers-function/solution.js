const solution = (progresses, speeds) => {
    const answer = []; // 답안을 저장할 배열

    while (progresses.length !== 0) { // 남은 작업이 없을 때 까지 반복
        let count = 0;

        for (let i = 0; i < progresses.length; i++) {
            progresses[i] += speeds[i]; // 작업 진행도 각 속도만큼 증가
        }

        if (progresses[0] >= 100) { // 남은 작업중 첫 순서의 작업이 완료되었을 때
            while (progresses[0] >= 100) { // 앞부터 완료된 작업을 세고 삭제처리
                progresses.shift();
                speeds.shift(); // 속도 목록도 작업 목록과 같이 떄문에 동일하게 삭제처리
                count++;
            }

            answer.push(count);
        }
    }

    return answer;
}