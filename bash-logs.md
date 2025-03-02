# Logs


> Bash


## Points


10 points


## Brief description


You are to create a script which finds logs, validates and prints them in descending order.


## Environment


* Commit your solution to `bash/logs` branch
* Script's name must be `parse-log.sh`
* Put the script in `bash/logs` directory


## Arguments


```
parse-log.sh [OPTION]... DIR
   DIR - logs directory


OPTIONS:
   -o, --order [up|down]         sort order, default is 'up'
   -l, --lines NUMBER            limit, default is '10'
```


Positional:
1. The directory where the logs are located


Named:
* `-o` or `--order`: `up` or `down` with `up` as a _default_ value
* `-l` or `--lines`: limit with `10` as a _default_ value


## Requirements


You have to collect all data from `.log`-files inside the provided directory.


We assume that a valid log is a line in `.log`-file which follows this format:


> `[_<descriptor>_]␣dd:mm:yyyy␣<id>␣<message>`
>
> `_` - a space character (` `)
>
> `␣` - a whitespace character (` `, `\n`, `\r`, etc.)
>
> `dd:mm:yyyy` - a timestamp (day-month-year)
>
> `<descriptor>` - one of `INFO`, `DEBUG`, `WARNING`, `ERROR`
>
> `<id>` - a non-negative integer
>
> `<message>` - a maybe empty sequence of word characters (any Latin character or an underscore)


You have to filter all previously collected logs and sort them in the **descending order** by `id` parameter.


Print exactly the selected number of logs:


* Choose the first `limit` logs if `up` option was selected
* Choose the last `limit` logs if `down` option was selected


If the valid logs count is less than `limit` then print them all.


## Tests


1. (2 points)
  * One file
  * No invalid data


2. (3 points)
  * Some data is broken


3. (5 points)
  * Large log files
  * Broken data
  * Complex directory structure
  * Bad names


## Advices & Hints


> You do not have to follow all of them. You are free to implement your own solution.


* Use regular expressions to filter logs
* You might need to use `sort`, `head`, `tail` commands
* `cat` command can accept more than 1 argument
* You might need to create a temporary file to store all the data

