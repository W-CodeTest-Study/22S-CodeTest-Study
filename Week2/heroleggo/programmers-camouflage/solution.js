const solution = (clothes) => {
    let answer = 1;
    const map = new Map(); // map 자료형 활용 (python에선 dict와 유사)
    
    clothes.forEach(([detail, position]) => {
        if (map.get(position) === undefined) { // 종류에 아직 옷이 없을 경우 새 배열로 저장
            map.set(position, [detail]);
        } else { // 이미 다른 옷이 있을 경우, 다른 옷과 새로운 옷을 포함한 배열을 저장
            map.set(position, [...map.get(position), detail]);
        }
    });
    
    map.forEach((value) => {
        answer *= (value.length + 1); // 부위별로 착용하는 경우의 수 + 착용하지 않는 경우까지 포함
    })
    
    return answer - 1; // 모두 착용하지 않은 경우는 제외
}