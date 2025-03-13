
function solution(sequence) {
    var answer = 0;
    const purse1 = sequence.map((num,index)=> index%2===0?num*1:num*-1);
    const purse2= sequence.map((num,index)=> index%2===0?num*-1:num*1);

    const dp1=[];
    const dp2 = [];
    const len = sequence.length;

    dp1.push(purse1[0]);
    dp2.push(purse2[0]);
    answer = Math.max(answer, dp1[0],dp2[0]);
    for(var i=1;i<len;i++){
        dp1.push(Math.max(dp1[i-1]+purse1[i], purse1[i]));
        dp2.push(Math.max(dp2[i-1]+purse2[i], purse2[i]));
        answer = Math.max(answer, dp1[i], dp2[i]);
    }
    return answer;
}