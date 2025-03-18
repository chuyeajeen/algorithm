function solution(numbers) {
    let answer = '';

    numbers.sort((a,b)=>{
        let strA = a.toString();
        let strB = b.toString();

        return (strB + strA) - (strA + strB);
    });

    return numbers[0] ===0 ? '0':numbers.join('');

}