# Sorting notes
> List of notes I take while learning about all the different sorting algorithms

### Algorithm analysis
- Worst case: Max(T(n))
- Best case: Min(T(n))
- Average case: E(T(n))

π© **Note:**
Average case requires knowledge of statistical distribution of inputs (can be biased)
  - Approx. to worst case (when the best case is the exception)
  - Approx. to best case (when the worst case is the exception)
  
### Asymptotic analysis
- πΆβππππππππ(Big O):
  - [x] Works on _Upper bound_ of function (worst case)
  - [x] May be asymptotically tight 2nΒ² = O(nΒ²)
  - [x] May not be asymptotically tight 2n = O(nΒ²)
- Ξβππππππππ(Theta):
  - [x] Works on tight bound (fix complexity)
  - [x] We user theta when complexity of the algorithm is almost fixed for all cases
- Ξ© β ππππππππ (Big-Omega):
  - [x] Works on _Lower bound_ of function (best case)
  - [x] May be asymptotically tight 2nΒ² = Ξ©(nΒ²)
  - [x] May not be asymptotically tight 2nΒ³ = Ξ©(nΒ²)

### Recurrences
> Simply formulate the time or space complexity of a program as a mathematical function π(π)
