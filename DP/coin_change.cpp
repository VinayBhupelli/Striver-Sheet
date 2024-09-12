// recursion
// // base condition
// if(sum == 0)
//     return 1;
// if(N == 0)
//     return 0;
// // not include condition
// long long int not_include = count(coins, N-1, sum);
// long long include = 0;
// // include
// if(coins[N-1] <= sum)
// include = count(coins, N, sum-coins[N-1]);

// return include + not_include;