const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin
});
let input = [];
rl.on('line', (line) => {
  input.push(line);
}).on('close', () => {
    const n = parseInt(input[0]);
    const a = Array(n).fill(0).map((_, i) => BigInt(i + 1));
    if (n === 0) {
      console.log(1)
      return;
    }
    let len = n;
    
    while (len > 1) {
      let mid = len >> 1;
      for (let i = 0; i < mid ; i++) {
        a[i] = a[i] * a[len - i - 1];
      }
      if (len % 2) len = mid+1;
      else len = mid;
    }

  console.log(a[0].toString());
});