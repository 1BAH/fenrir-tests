# Git Essentials


> Git


---


## Points




| Task | Points |
| ---- | ------ |
| 1    | 1      |
| 2    | 1      |
| 3    | 2      |
| 4    | 1      |
| 5    | 1      |
| 6    | 1      |
| 7    | 1      |
| 8    | 2      |
| 9    | 1      |
| 10   | 1      |
| 11   | 3      |


> Total: 15


---


## Algorithm


1. Use `git fetch` и `git remote` to add the remote repository
2. Checkout to a task branch (it's better to use `git switch`). This way you'll add all required branches to your local repository
3. Solve a task
4. Push the solution to `origin`
5. Solve the next task and so on


> We advise you to solve the tasks in the presented order. However, you can skip them, it won't affect estimation.


## Description


### Task 1. (1)


Merge branch `2` into `1`


A merge conflict will occur. Resolve it:


1. Delete the file which was removed in one of the branches
2. Preserve all changes in the other file: the numbers must be ordered


Merge commit's message has to be `3`.


### Task 2. (1)


Rebase branch `4` onto `3`


For each file choose the changes from the branch which name matches the filename.


### Task 3. (2)


We have previously studied how to resolve different merge conflicts but not all [types](https://github.com/git/git/blob/cb0ae672aeabefca9704477ea8018ac94f523970/merge-ort.c#L515) have been covered. That is why you are to create a merge conflict of a new type yourself.


Using branch `6`, create the merge conflict that occurs after running


```shell
git merge 6
```


on branch `5`.


### Task 4. (1)


Assume that branches `8` and `9` bring independent changes (their changes affect different files). Repository structure follows this diagram:


```
    * <- (9)
    *
   /
  * <- (8)
  *
 /
* <- (7)
*
```


You have to "balance this tree" so that your repository follows this diagram:


```
* <- (9)
*
| * <- (8)
| *
|/
* <- (7)
*
```


### Task 5. (1)


You are to undo the changes that were brought by commit `21`. Use the _appropriate_ command. **Do not change neither commit's message nor its body!**


> Branch `10`


### Task 6. (1)


You are to roll back to commit `24`.


> Branch `11`


### Task 7. (1)


Rename the last commit (`28`) so that its message is `27`.


> Branch `12`


### Task 8. (2)


This time you have to solve a more complex task: you need to find a commit and rename it.


1. Do not try to do it manually! There are almost 7000 commits, use the commands provided by `git`.
2. The required commit is the one that adds your plant (find it [here](https://docs.google.com/spreadsheets/d/1cgSLkz1nIdDo7cNBz7DystP8CVYqY7s--0nUvO1FTNY/edit?usp=sharing)). We guarantee that all changes follow the lexicographical order.
3. The new name must be `magnolia`
4. Do not forget to change `credentials.config`: replace `[id]` with your *id* from the table.


> When changing `credentials.config` create a commit with message `7000` and **squash** it with the previous one. As a result, you'll have an only commit `7000`.


> Your changes might affect quite a lot of commits so it will take several minutes. Do not be afraid that `git` might get frozen for a while!


> Branch `13`


### Task 9. (1)


Apply the changes of commit `6003` to branch `14`. As a result, all numbers in `9.txt` will follow descending order.


> Preserve commit's message!


### Task 10. (1)


When working with scripts in Windows, one can encounter several problems. Assume your collaborator has commited a script `win.sh` from Windows.


Try executing this script. What happens?


Fix all errors so that `win.sh` prints `HI` when it is invoked.


> Use [Stack Overflow](https://stackoverflow.com/) to find solutions


> Branch `16`


### Task 11 (3)


[Git hooks](https://git-scm.com/book/ms/v2/Customizing-Git-Git-Hooks) is a useful feature. You are to create a [hook](https://en.wikipedia.org/wiki/Hooking) that validates commit's message and prevents from commiting when the message does not follow the format: `[␣DESCRIPTOR␣]␣DESCRIPTION`


* `DESCRIPTOR` is one of `ADD`, `FIX` or `DEL`
* `DESCRIPTION` is a sequence of numbers and latin symbols (both lower and upper case)
* `␣` is a _whitespace_ character


> Use **bash**!


> Branch `17`


## Advices & Hints


* [Documentation](https://git-scm.com/docs)
* [Sources](https://github.com/git/git)
* [Atlassian's guides](https://www.atlassian.com/git)

