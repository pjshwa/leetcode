let string = "ATAATTACCAACATCATAATTACCAACATCATAATTACCAACATCATAATTACCAACATCATC";
let pattern = "TT";

let M = pattern.length;
let N = string.length;
let skip;
let res = [];
let map = {};

for(let j=0;j<M;j++){
  map[pattern[j]] = j;
}

for(let i=0;i<=N-M;i+=skip){
  skip=0;
  for(let j = M-1;j>=0;j--){

    if(pattern[j] != string[i+j]){
      skip = Math.max(1,j - (map[string[i+j]] || -1));
      break;
    }
  }
  if(skip == 0){
    res.push(i);
    skip++;
  }
}

console.log(res);
