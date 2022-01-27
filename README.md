# Fdf
FDF / Hive Helsinki

## :diamond_shape_with_a_dot_inside: **Project's goal:**

This program is about drawing a binary map with pixel lines into an extrnal window by mlx library.
The idea is that the given map will contain grounds with low altitude and parts where
the altitude will be higher, and printing it in isometric projection for example will
make the higher altitude ground looks more like 3d printing.

## :warning: **NOTE:**

This project was mainly done to work on Hive's/ecole 42 Mac Os, hence there are limitations of the project's
controls when mlx window opens, and some linking diffrences if the project running on other Mac devices or Linux.

## :arrow_forward: **To start the program:**

1- ```git clone git@github.com:omaralsakka/Fdf.git ```

2-  ```make``` at the terminal

## :green_square: Run

1- inside **test_maps** folder plenty of binary maps that you can write after the program name in this format:

```./fdf ./test_maps/42.fdf```

2-  simply press ```esc``` to close the window

3-  finally write ```make fclean``` to delete all static libraries and created programs

## :penguin:FOR LINUX USERS:

1-  folllow the comments inside the **Makefile** to be able to link MLX library properly

2-  all the window keys **"except esc button"** will not be running on Linux


![Screenshot from 2022-01-27 15-56-05](https://user-images.githubusercontent.com/81321172/151372877-666ea8de-91fe-42ce-b657-3aff1b7fabdb.png)
