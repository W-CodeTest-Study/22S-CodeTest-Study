const solution = (bridgeLength, weight, truckWeights) => {
    let answer = 0;
    const queue = []; // 다리 위에 올라와 있는 트럭
    let current_weight = 0; // 현재 다리가 지탱하는 트럭 무게의 합
    while(truckWeights.length > 0) {
        answer++; // 1초 지나감
        if (queue.length === bridgeLength) { // 다리가 꽉 찼을 경우 = 제일 먼저 간 트럭이 나갈 차례
            current_weight -= queue.shift(); // 다리에서 내보내주기
        }
        if (current_weight + truckWeights[0] > weight) { // 만약 새 트럭이 올라갈 수 없을 때
            queue.push(0); // 빈 자리 나타냄
        } else {
            let newTruck = truckWeights.shift(); // 아닐 경우 새 트럭 들어갈 준비
            current_weight += newTruck; // 무게 더해주고
            queue.push(newTruck); // 다리에 올리기
        }
    }
    
    // 다 끝났을 경우, 마지막 자리에 있는 트럭이 나갈 때 까지 다리 길이만큼 걸리기 때문에 더해주기
    answer += bridgeLength;

    return answer;
}
