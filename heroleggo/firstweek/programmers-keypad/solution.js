// 배열로 데이터를 쓰고 싶지 않아서 x, y, data 사용한 클래스 만듬
// x -> x 좌표, y -> y 좌표, data -> index + 1 (0 계산하기 편하게 하려고)
class Position {
    constructor(x, y, data) {
        this.x = x;
        this.y = y;
        this.data = data;
    }
}

const solution = (numbers, hand) => {
    const answer = [];
    // 왼손, 오른손의 첫 위치 초기화 (*, #)
    let leftPos = new Position(3, 0, -1);
    let rightPos = new Position(3, 2, -1);
    // 키패드 자리 초기화
    const numset = Array(9).fill(0).map((v, i) => new Position(parseInt(i / 3), i % 3, i + 1));
    numset.push(new Position(3, 1, 0));
    
    numbers.forEach((n) => {
        // 맨 왼쪽 줄일 때 왼손 사용
        if (n % 3 === 1) {
            answer.push('L');
            leftPos = numset.find((v) => v.data === n);
        } else if (!(n % 3) && n) { // 맨 오른쪽 줄일 때 오른손 사용
            answer.push('R');
            rightPos = numset.find((v) => v.data === n);
        } else { // 각 손가락의 위치에서 가야 하는 곳의 거리 계산
            const v = numset.find((v) => v.data === n);
            const leftDiff = Math.abs(v.x - leftPos.x) + Math.abs(v.y - leftPos.y);
            const rightDiff = Math.abs(v.x - rightPos.x) + Math.abs(v.y - rightPos.y);
            if (leftDiff > rightDiff) { // 왼손이 더 멀때
                answer.push('R');
                rightPos = v;
            } else if (leftDiff < rightDiff) { // 오른손이 더 멀때
                answer.push('L');
                leftPos = v;
            } else { // 동일한 거리일 때 손잡이에 따라 변경
                if (hand === 'left') {
                    answer.push('L');
                    leftPos = v;
                } else {
                    answer.push('R');
                    rightPos = v;
                }
            }
        }
    })
    
    return answer.join('');
}