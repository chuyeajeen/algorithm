function solution(name, yearning, photo) {
    var answer = [];
    for(const target of photo ){
        var sum =0;
        for(const num of target){
            const index = name.findIndex(tempTarget => tempTarget === num);
            if(index!==-1){
                sum+=yearning[index]
            }
        }
        answer.push(sum);
    }
    return answer;
    // return photo.map((v)=> v.reduce((a, c)=> a += yearning[name.indexOf(c)] ?? 0),0);

}
