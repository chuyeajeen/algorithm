function solution(k, tangerine) {
    //배열로 초반에 접근하였으나, size idx 에 넣어야하므로 map 이 적합 (배열로 접근 시 사이즈만큼 arr 을 생성할수없음)
    let countMap = new Map();

    for (let size of tangerine) {
        countMap.set(size, (countMap.get(size) || 0) + 1);
    }

    let sortedCounts = [...countMap.values()].sort((a, b) => b - a);

    let sum = 0;
    let answer = 0;

    while (sum < k && answer < sortedCounts.length) {
        sum += sortedCounts[answer];
        answer++;
    }

    return answer;
}
