# task-02

For this task we are going to compute the Mandelbrot set, but we will be using threads to speed up the computation!

### Clamshell Users

Before starting this task, run the following command in the task folder.

```shell
make clamshell
```

This will update and move the `malen`, `malen-bokeh`, `nlohmann`, and `fmt` libraries into place.

## Task

Follow along in class! We want to implement the following:

* Mandelbrot set

With the starter code and some newly added code, we will be computing the Mandelbrot set for a given region of the complex plane. When we are done we should be able to produce the following: http://crab.rutgers.edu/~nesan/mandelbrot.html

## Building

Trying building your program with:

```shell
make
```

## Running

Try running the program with:

```shell
./main.exe data/configuration.json
```

Try tweaking some of the values in `data/configuration.json` we can control the detail and performance of the computations!

### Turtleshell Users

If you cloned the repository in the correct location, you should be able to navigate to the assignment directory on your PC (not in VS Code/Docker). In the task-02 directory will be a file named `mandelbrot.html` that you can open in your web browser.

e.g. on my Windows PC that path is:

```text
C:\Users\Lnk2past\turtleshell\assignment-08-Lnk2past\task-02\mandelbrot.html
```

### Clamshell Users

Run the command:

```shell
make move-plot
```

Then in your web browser go to the website, replacing `NETID` with your own Rutgers NetID:

```
http://clam.rutgers.edu/~NETID/mandelbrot.html
```

## Testing

Try testing the program with:

```shell
make test
```
