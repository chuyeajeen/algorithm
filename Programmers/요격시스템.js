function solution(targets) {
    var cur=targets[0];
    var answer=1;
    targets.sort((a,b)=>a[0]-b[0]);
    targets.map(target =>{
        if(cur[1]<=target[0] ) {
            cur = target;
            ex.push(target);
            answer++;
        }
        else{
            cur = [Math.max(cur[0], target[0]), Math.min(cur[1], target[1])];
        }
    })
    return answer;
}