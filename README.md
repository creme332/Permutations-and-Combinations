# Combinations 

Explanation for how algorithm works and how to derive it using logic

# Permutations 
![image](https://user-images.githubusercontent.com/65414576/152680821-783bb8dd-16d9-4e30-91dc-889c82437283.png)

## Logic :
Set `all` : stores all possible permutations. 

Multimap `ChooseFrom` : 
- Key : elements which are to be permuted.
- Value : Is element unused?
- If `ChooseFrom ['A'] == 0`, we cannot use `'A'` again.


There are `n` places.

1st plane has `n` possibilities

2nd place has `n-1` possibilities

...

For each place, try all possibilities.

Duplicate arrangements will be calculated only if there are repeating elements in `ChooseFrom`. However, a set will filter out duplicates.


## Reasons for using a set container `all` :
  
- To get rid of duplicates.

## Alternative to global scope of `all` :

```
std::set <std::string> perm(std::string current, std::multimap <char, bool> ChooseFrom) {

      static std::set <std::string> all;
  
      :::
      
      :::
    
      :::
    
      return all;
  
}
```

## Reasons for using a multimap, `ChooseFrom` :
- Elements stored in it are sorted automically. (This is essential for program to work when there are repeating elements)
- Repeating elements are allowed.
