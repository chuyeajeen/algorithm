function solution(n, lost, reserve) {

    let realReserve = reserve.filter(idx => !lost.includes(idx));
    let realLost = lost.filter(idx => !reserve.includes(idx));

    let answer = n - realLost.length;

    realLost.sort();
    realLost.forEach(lostIdx => {
        if(realReserve.includes(lostIdx-1)){
            answer= answer+1;
            realReserve = realReserve.filter(index=>index !==lostIdx-1);
        }
        else if(realReserve.includes(lostIdx+1)){
            answer = answer+1;
            realReserve = realReserve.filter(index=>index!==lostIdx+1);
        }
    });

    return answer;
}
