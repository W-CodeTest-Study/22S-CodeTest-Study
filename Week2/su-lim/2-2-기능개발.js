function solution(progresses, speeds) {
    let answer = [];

    // need_time : 작업에 필요한 시간을 계산하기 위해 사용하는 변수
    let need_time = 0;

    while(progresses != false ){
        
        /* 1. 가장 먼저 처리해야하는 작업에 대해 필요한 시간을 계산 */
        answer.push(1);

        now_progress = progresses.shift();
        now_speed = speeds.shift();
        
        need_time = Math.ceil( (100 - now_progress) / now_speed ); // 작업 시간에 필요한 시간 계산 (3.5일 -> 4일)

        /* 2. 기존에 값들을 need_time만큼 업데이트 */
        for(let i=0; i < progresses.length; i++){
            progresses[i] = progresses[i] + (speeds[i] * need_time);
        }

        /* 3. 100 이상인 작업들을 progresses에서 뺌 */
        while(progresses[0] >= 100){
            answer[answer.length-1] += 1;
            progresses.shift();
            speeds.shift();
        }
    }

    return answer;
}