# Combinations 
![image](https://user-images.githubusercontent.com/65414576/152682473-6429be73-e592-42f2-9199-72bd811494cc.png)

`all` : stores all possible combinations. 

`ChooseFrom` : stores elements which are available to be chosen.

The offset $i$ prevents permutations of a combination from being created.
## `comb()` :
>Given $n$ unique elements, choose $r$ elements without repetition. The same element cannot be chosen more than once.

Eg : Given `{A,B,C}` and $r = 2$,

`all = {AB, AC, BC}`

$i$ : offset for `ChooseFrom`

If $i = 2$ and `ChooseFrom = {'A', 'B', 'C', 'D'}`, we are allowed to choose elements starting from index $2$ :   `{'C', 'D'}`


## `comb1()` :

>Given $n$ unique elements, choose $r$ elements with repetition. The same element can be chosen more than once.

Eg : Given `{A,B,C}` and $r = 2$, 

`all = {AA, AB, AC, BB, BC, CC}`

This function can be used instead of stars and bars to solve these types of questions :

>Find the number of solutions to the equation $x + y + z = 5$, where $x,y,z$ are non-negative integers.

Calculate `comb1(3,0,"")` given `ChooseFrom = {0, 1}`.

Answer = `all.size()` = $7C2$

## `comb2()` :
>Given $n$ elements, some of which may not unique, choose $r$ elements. You cannot use more elements than given. 

Ex1 : `Given {A, A, B, C} and r = 2`,

all = AA, AB, AC, BA, BB, BC, CA,CB, CC 

Note : At most 2 As are used.
	
Ex2 : Given `{A, A, B, C}` and $r = 3$,

`all = AAB, AAC, ABC `


# Permutations 
![image](https://user-images.githubusercontent.com/65414576/152680821-783bb8dd-16d9-4e30-91dc-889c82437283.png)

## `perm1()` :
>Given n elements (duplicates allowed), find all possible arrangements.

Set `all` : stores all possible permutations. 

Multimap `ChooseFrom` : 
- Key : elements which are to be permuted.
- Value : Is element unused?
- If `ChooseFrom ['A'] == 0`, we cannot use `'A'` again.


There are `n` places.

1st plane has `n` possibilities.

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
>Given $n$ unique elements, choose $r$ elements with repetition, and arrange.

There are $r$ places to fill using $n$ elements. Any element $n_k$ can be at multiple places.

At each place $r_i$, there are $n$ ways to place an element.

Recursion is used to test all possibilities. We stop when `current` reaches required size. 

There is no offset $i$ here since we also have to arrange.