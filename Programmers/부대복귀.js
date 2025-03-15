function solution(n, roads, sources, destination) {
    const answer= [];
    const graph = Array.from({ length: n + 1 }, () => []);

    for (let [a, b] of roads) {
        graph[a].push(b);
        graph[b].push(a);
    }

    const shortCut = Array(n + 1).fill(-1);
    const queue = [destination];
    shortCut[destination] = 0;

    while(queue.length>0){
        const value = queue.shift();
        graph[value].forEach(a=>{
            if(shortCut[a]===-1){
                shortCut[a] = shortCut[value]+1;
                queue.push(a);
            }
        })
    }

    sources.forEach(source=>{
        answer.push(shortCut[source]);
    });
    return answer;
}