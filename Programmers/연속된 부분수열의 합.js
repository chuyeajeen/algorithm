function solution(sequence, k) {
    var answer = [];
    sequence.forEach((number, index)=>{
        var sum = number;
        var addIdx = 0;
        const startIdx = index;
        while(sum<k){
            sum = sum+sequence[index+addIdx];
            addIdx = addIdx+1;
        }
        if(sum ===k && answer[1]-answer[0] > addIdx){
            answer=[startIdx, startIdx+addIdx];
        }
    })
    return answer;
}