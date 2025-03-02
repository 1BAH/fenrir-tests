# LU


> Bash


## Points


10 points


## Brief description


You are to implement $\mathtt{LU}$ decomposition.


## Environment


* Commit your solution to `bash/lu` branch
* Script's name must be `decomposition.sh`
* Put the script in `bash/lu` directory
* You can use `bc` command


## Arguments


1. Path to `.csv`-file with input matrix
2. Path to `.csv`-file where to store $\mathtt{L}$ matrix
3. Path to `.csv`-file where to store $\mathtt{U}$ matrix
4. Number of significant digits in answer


## Requirements


All data stored in CSV-format (Google it!)


> Input csv-file might be broken: it can miss an LF character at the end


> Output files might already exist and contain some data. In that case you should override it


It is guaranteed that the all leading principal minors of the input matrix are non-zero


In order to make $\mathtt{L}$ and $\mathtt{U}$ matrices unique, we want $\mathtt{L}$ to satisfy the following condition:


$$
diag(\mathtt{L}) = \langle1,\,\ldots,\, 1\rangle
$$


It is forbidden to mutate input data.


## Examples


Input: $\begin{Vmatrix} 3 & 1 & 2 \\ 4 & 13 & 12 \\ 7 & 20 & 103\end{Vmatrix}$, precision = 2


Output: $\mathtt{L} = \begin{Vmatrix} 1.00 & 0.00 & 0.00 \\ 1.33 & 1.00 & 0.00 \\ 2.33 & 1.51 & 1.00\end{Vmatrix}$, $\mathtt{U} = \begin{Vmatrix} 3.00 & 1.00 & 2.00 \\ 0.00 & 11.67 & 9.33 \\ 0.00 & 0.00 & 84.20\end{Vmatrix}$


## Advices & Hints


> You do not have to follow all of them. You are free to implement your own solution.


* Bash does not support multidimensional array so you have to either transform 2-dimensional array to 1-dimensional or use associative arrays
* Bash does not support floating-point calculations. Use `bc`
* Be careful with the precision. Do not round numbers as long as it is possible
