# Combinations 

`all` : stores all possible combinations. 

`ChooseFrom` : stores elements which are available to be chosen.

*i* : offset for `ChooseFrom`

If *i* = 2 and `ChooseFrom = {'A', 'B', 'C', 'D'}`, we are allowed to choose elements starting from index $2$ :   `{'C', 'D'}`. The offset *i* prevents permutations of a combination from being created.
## `comb()` :
>Given n unique elements, choose r elements without repetition (the same element cannot be chosen more than once).

Eg : Set `ChooseFrom = {A,B,C}` and `r = 2`,

`all = {AB, AC, BC}`

![image](https://user-images.githubusercontent.com/65414576/155157469-e278d864-1500-4e58-996d-3f5bd2ece10c.png)


## `comb1()` :

>Given n unique elements, choose r elements with repetition (the same element can be chosen more than once).

Eg : Set `ChooseFrom = {A,B,C}` and `r = 2`, 

`all = {AA, AB, AC, BB, BC, CC}`

## `comb2()` :
>Given n elements, some of which may not unique, choose r elements. You cannot use more elements than given. 

Eg1 : Set `ChooseFrom = {A, A, B, C}` and `r = 2`,

`all = {AA, AB, AC, BA, BB, BC, CA,CB, CC} `

Note : At most 2 As are used.
	
Eg2 : Given `{A, A, B, C}` and r = 3,

`all = AAB, AAC, ABC `


# Permutations 
![image](https://user-images.githubusercontent.com/65414576/152680821-783bb8dd-16d9-4e30-91dc-889c82437283.png)

## `perm1()` :
>Given n elements (unique or not), find all possible arrangements.

The multimap `Letters` holds the n elements.

### Code explanation ###
`all` : stores all possible permutations. 

Multimap `ChooseFrom` : 
- Key : elements which are to be permuted.
- Value : Is element unused?
- If `ChooseFrom ['A'] == 0`, we cannot use `'A'` again.


There are `n` places.

1st place has `n` possibilities.

2nd place has `n-1` possibilities.

...

For each place, try all possibilities.

Duplicate arrangements will be calculated only if there are repeating elements in `ChooseFrom`. However, a set will filter out duplicates.


### Reasons for using a set container `all` :
  
- To get rid of duplicates.

### Alternative to global scope of `all` :

```
std::set <std::string> perm(std::string current, std::multimap <char, bool> ChooseFrom) {

      static std::set <std::string> all;
  
      :::
      
      :::
    
      :::
    
      return all;
  
}
```

### Reasons for using a multimap, `ChooseFrom` :
- Elements stored in it are sorted automically. (This is essential for program to work when there are repeating elements)
- Repeating elements are allowed.

## `perm2()` :
>Given n unique elements, choose r elements with repetition, and arrange.

Eg : Set `ChooseFrom = {a,b,c}` and `r=2`,

`all = {aa, ab, ac, ba, bb, bc, ca, cb, cc}`

### Code explanation
There are r places to fill using n elements. Any element n_k can be at multiple places.

At each place r_i, there are n ways to place an element.

Recursion is used to test all possibilities. We stop when `current` reaches required size. 

There is no offset i here since we also have to arrange.

# Cyclic permutations #
> Arrange n unique elements around a circle.

Same logic as Permutations except arrange n-1 elements instead of n elements.
