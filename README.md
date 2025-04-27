
# Fract-ol

Welcome to **Fract-ol**, a project developed as part of the 42 curriculum.This program generates and displays several types of fractals using the MiniLibX graphics library.

## Fractals Implemented

- **Mandelbrot**
- **Julia**
- **Burning Ship**
- **Celtic Mandelbrot**
- **Mandelbox**
- **Tricorn**

Each fractal is rendered with high precision and offers real-time interaction through keyboard and mouse inputs.

## Features

- Zoom in and out on fractals
- Move around the fractal plane
- Change fractal parameters dynamically
- Adjust color schemes
- Multi-fractal selection at runtime
- Smooth and responsive user interface

## Installation

### Requirements

- macOS or Linux
- gcc compiler
- Make
- MiniLibX library

### Clone the repository

```bash
git clone https://github.com/your_username/fract-ol.git
cd fract-ol
```

### Compile

```bash
make bonus
```

## Usage

```bash
./fractol [fractal_name]
```

Available fractal names:

- `mandelbrot`
- `julia`
- `burningship`
- `celtic`
- `mandelbox`
- `tricorn`

Example:

```bash
./fractol julia -0.7269 0.1889
```

## Controls

| Action              | Key/Mouse         |
| ------------------- | ----------------- |
| Zoom in             | Mouse Scroll Up   |
| Zoom out            | Mouse Scroll Down |
| Move view           | Arrow Keys        |
| Increase iterations | `+` key           |
| Decrease iterations | `-` key           |
| Change color scheme | `C` key           |
| Reset zoom          | `R` key           |
| Exit                | `ESC` key         |

## Algorithm Explanation

- Each pixel on the screen is mapped to a complex number based on the current zoom and view.
- The fractal formula is iteratively applied to determine if the point escapes to infinity.
- A `char **` 2D array is used to represent and store pixel data efficiently.
- Colors are assigned using a custom **color algorithm** based on the number of iterations it took for the point to escape.
- Pressing the `C` key changes the current color scheme dynamically, allowing different visualization styles.
- Dynamic memory management is handled manually:
  - `malloc` is used to allocate memory for pixel data and other structures.
  - `free` is called appropriately to prevent memory leaks and ensure efficient resource usage.

## Screenshots

![Screenshot from 2025-04-27 10-24-43](https://github.com/user-attachments/assets/88913b7b-4b8d-4db0-94a5-faecc7971547)
![Screenshot from 2025-04-27 09-42-30](https://github.com/user-attachments/assets/4311c3c7-f5a4-49fe-bccb-f0f53ce77abc)
![Screenshot from 2025-04-27 09-44-19](https://github.com/user-attachments/assets/cef81411-c08c-44c7-9be5-a28fa71bd052)
![Screenshot from 2025-04-27 09-42-50](https://github.com/user-attachments/assets/36a1284b-4b93-409e-9934-44dd04a82a7a)
![Screenshot from 2025-04-27 09-45-02](https://github.com/user-attachments/assets/04dedcf5-0d40-41c3-9d81-4702b64d1bea)
![Screenshot from 2025-04-27 09-43-30](https://github.com/user-attachments/assets/9e5f2d03-d1d8-407b-804d-5b071377fac0)

## License

This project is part of the 42 School curriculum and follows its academic honesty policy.

---
