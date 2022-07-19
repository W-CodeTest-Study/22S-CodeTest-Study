const getHead = (str) => str.match(/\D+/)[0];
const getNumber = (str) => str.match(/\d+/)[0];

const solution = (files) => {
    console.log(files);
    files.sort((a, b) => {
        // same head
        const headA = getHead(a).toUpperCase();
        const headB = getHead(b).toUpperCase();
        if (headA === headB) {
            // same number
            const numA = parseInt(getNumber(a));
            const numB = parseInt(getNumber(b));
            if (numA === numB) {
                return 0;
            } else {
                // number 비교를 통한 정렬
                return numA - numB;
            }
        } else {
            // 대소비교를 통한 사전순 정렬
            return headA < headB ? -1 : headA > headB ? 1 : 0;
        }
    })
    return files;
}