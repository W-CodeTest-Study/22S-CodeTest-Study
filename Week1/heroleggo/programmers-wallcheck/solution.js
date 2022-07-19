// (arr.length)Pn 이라고 생각하면 됨
const getPermutation = (arr, n) => {
    if (n === 1) { // 1개이면 하나씩 배열로 만들어서 반환
        return arr.map((i) => [i]);
    } else {
        const result = [];
        arr.forEach((v, i) => {
            // 한자리씩 옮겨가면서 원소 뺀 배열
            const remainder = arr.slice(0, i).concat(arr.slice(i + 1, arr.length));
            // 해당 배열에서 재귀 수행
            const permutations = getPermutation(remainder, n - 1);
            // 반환할 결과에 빼놓은 원소 넣어서 추가
            result.push(...permutations.map((p) => [v, ...p]));
        })
        
        return result;
    }
}

const solution = (n, weak, dist) => {
    dist.sort((a, b) => b - a); // 큰 범위 커버치는 놈부터 씀

    // 두 바퀴로 만들기 -> 계산할때 편하게 하려고
    const data = weak.concat(weak.slice(0, weak.length - 1).map((v) => v + n));

    for (let i = 1; i <= dist.length; i++) {
        // 순열 가져와서 안에 다 커버되는지 테스트함
        const permutation = getPermutation(dist, i);

        for (let p = 0; p < permutation.length; p++) {
            // 사용할 순열 가져옴
            const permu = permutation[p];

            for (let j = 0; j < weak.length; j++) {
                // 각 자리부터 쭉 리스트 쓰기
                // n = 10, weak = [1, 3, 5, 7]이라면
                // [1,3,5,7] [3,5,7,11] [5,7,11,13] [7,11,13,15]
                let path = data.slice(j, weak.length + j);

                for (let k = 0; k < permu.length; k++) {
                    // path의 첫 자리부터 허용되는 값까지 가 did
                    const did = path[0] + permu[k];
                    // path에서 did 안에 있는것들 날리기
                    path = path.filter(v => v > did);
                    
                    // 다 삭제되어서 path의 길이가 0일 경우 해당 값 반환
                    if (!path.length) return i;
                }
            }
        }
    }
    
    return -1;
}