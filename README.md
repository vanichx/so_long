**so_long**

### Description

The **so_long** project is a compact 2D game where the player’s goal is to collect items on a map and then escape through an exit, taking the shortest possible path. Built in C using the **MiniLibX** graphics library, this project helps solidify skills in texture and sprite management, window handling, and basic gameplay programming.

### Key Features

- **Map Design**: Maps are built with specific characters: walls, collectibles, an exit, and a player’s starting position.
- **Movement**: The player moves with W, A, S, and D keys in four directions—up, down, left, right.
- **Game Rules**: Players cannot move through walls and must collect all items to reach the exit.
- **Display**: Each move counts and is displayed in the console.
- **Responsive Graphics**: The game uses 2D visuals, where ESC or window close events will cleanly exit the program.

### Compilation and Usage

To compile the game, run the `Makefile` in the project directory. Pass a `.ber` format map file as an argument to start the game:

```bash
make
./so_long map.ber
```

**Map Requirements**:
- Must contain one exit, at least one collectible, and one starting position.
- Should be rectangular and enclosed by walls.

- **Error Handling**: If the map is misconfigured (e.g., lacks walls around the border, contains duplicate exits, or has multiple starting positions), the program will display an error message and exit cleanly.
- **Pathfinding Validation**: The program verifies that a valid path exists from the player’s starting position to each collectible and the exit.

### Bonus Features

For additional functionality, the project can include:
- **Enemies**: Introduce patrol enemies that cause the player to lose if touched.
- **Animations**: Add animations to sprites for smoother visual effects.
- **Movement Counter Display**: Show the movement count on-screen instead of in the console.

### Example Map

Here’s an example of a valid `.ber` map format:

```text
111111111
1P0000C01
100000001
1C0000E01
111111111
```

This simple 5x9 map layout includes walls (`1`), a starting position (`P`), collectibles (`C`), and an exit (`E`).

### Controls

- **Movement**: Use `W`, `A`, `S`, and `D` keys to move up, left, down, and right, respectively.
- **Exit**: Press `ESC` or click the close button on the game window to exit the game gracefully.

### Compilation and Execution

To compile the game, navigate to the project directory and run:

```bash
make
```

This will generate the `so_long` executable. To start the game, provide a valid `.ber` map file as an argument:

```bash
./so_long path/to/map.ber
```

### Requirements

- **Map File**: Ensure the map file follows the specified structure, with only valid characters (`1`, `0`, `P`, `C`, and `E`) and an enclosed boundary of walls.
- **MiniLibX Library**: The game requires the **MiniLibX** library for graphics and event handling. Ensure it’s installed and linked properly within the project setup.

### License and Contribution

Feel free to fork, modify, and use this project as desired. Contributions for improvements and optimizations are welcome!


# Here are the usefull resorces that I use right now to create this game 

1. https://harm-smits.github.io/42docs/libs/minilibx - Understand the basics of the MiniLibX lib, how to use ...

2. https://www.pixilart.com/draw - Very usefull web service to create your own pixel textures in png format.

3. https://convertio.co - Service which allows you convert your pictures to the XPM format , because the MiniLibX can read only this format .

4. https://www.imageconvert.org/png-to-xpm - Another service for convertation 

5. https://www.youtube.com/watch?v=9eAPbNUQD1Y&t=936s - Video that helps me to understand better , how to work with MiniLibX , this does not related to the so_long project but anyway for me was helpfull.
