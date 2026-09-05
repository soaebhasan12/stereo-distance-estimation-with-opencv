# Stereo Distance Estimation with OpenCV

This repository contains an existing C++/Qt desktop application for experimenting with stereo-camera calibration and rough distance estimation. It is **not** the YOLO pothole-detection project.

## About this copy

I downloaded this project to study and prepare it for a student portfolio. The original application code was not written by me. The source comments credit Keith Reilly and identify material adapted from *Learning OpenCV* by Gary Bradski and Adrian Kaehler, and *Practical OpenCV* by Samarth Brahmbhatt. Those attributions are retained in the source.

Changes made in this portfolio copy so far:

- Replaced the original README with this project and setup overview.
- Added Git ignore rules for Qt Creator settings and generated build files.
- Moved C++ files into `src`, the Qt Designer form into `forms`, and downloaded reference material into `docs/original_reference`; renamed source files to lowercase `snake_case` and updated the qmake project references.
- Replaced privileged shell cleanup commands with Qt file operations. The cleanup buttons now remove files only from their configured folders, do not use `sudo`, and stop with a warning if they encounter a subfolder or cannot remove a file.

Only describe changes you personally understand and have verified as your contribution.

## What the application does

- Captures still images from two cameras for stereo calibration.
- Uses chessboard images to calculate camera calibration and rectification data.
- Records video from a pair of cameras.
- Processes a pair of video files with stereo matching and displays a disparity view and an approximate depth for a small area near the image center.

This is an old learning project, not a production measuring tool. The depth estimate depends on camera calibration, camera placement, video quality, and the original processing code. It should not be treated as a reliable real-world measurement.

## Project layout

```text
.
|-- README.md
|-- stereo_distance.pro
|-- src
|   |-- main.cpp
|   |-- main_window.cpp
|   |-- main_window.h
|   |-- project_utils.h
|   |-- stereo_calibration.h
|   `-- stereo_processing.h
|-- forms
|   `-- main_window.ui
|-- docs
|   `-- original_reference
|       |-- original_code_index.txt
|       |-- original_code_structure.PNG
|       `-- original_project_report.pdf
```

The `src` folder contains the C++ source and headers. The Qt Designer form is in `forms`. The qmake project file stays at the repository root so the build command is easy to find. `docs/original_reference` keeps downloaded reference material separate from application code. Old Qt Creator settings and generated build output were removed because they are machine-specific and can be regenerated. Future local build output under `build/` is ignored by Git.

File names now use lowercase `snake_case`. This is a naming and organization change, not a rewrite of the original application logic.

## Requirements and build status

The project uses Qt Widgets and qmake. Its `.pro` file contains Linux OpenCV library paths, and the code uses older OpenCV C API headers and types. Many file paths are fixed to `/home/pi/OpenCV_Project`. As a result, this downloaded copy is Linux/Raspberry Pi-oriented and is **not ready to build on Windows or with an arbitrary modern OpenCV installation**.

I have not verified a complete build or camera run on this computer. A compatible Qt and legacy OpenCV environment, working stereo cameras, and the expected data folders are needed. A previously built executable, if available elsewhere, is not proof that the current source builds.

If you have a compatible Linux environment, run these commands from the project root:

```sh
qmake stereo_distance.pro
make
```

These are starting-point commands, not verified build instructions. The `.pro` file still points to `/usr/local/include/opencv` and `/usr/local/lib`; those paths and the OpenCV APIs may need careful, documented updates for your system. The application has no automated test suite in this download.

## Before running

The application expects its working folders under `/home/pi/OpenCV_Project`, including `Images`, `Videos`, and `CameraCalabration`. It also expects two cameras and calibration inputs. The cleanup buttons target those configured folders. The updated cleanup code removes files directly inside a target folder, refuses to remove subfolders, and shows a warning if a folder is missing or a file cannot be deleted.

This safety change is limited to the cleanup buttons. Other inherited code still contains hard-coded paths and shell commands, so the application has not had a full safety or portability review. Do not run it on important data until you have checked its paths and understand what each button does. Camera capture, calibration, and distance estimation have not been validated in this portfolio copy.

## Attribution and sharing

No license file was present in the downloaded project folder when this README was written. Confirm the original project's license and get permission where required before publishing the source, report, screenshots, or other included material. Keep all original author and book attributions intact. The included academic report appears to belong to the original project; do not redistribute it unless you have permission.

## What I am learning

I am using this project to study C++, Qt Widgets, camera calibration, stereo rectification, disparity, and the difference between relative depth and a trustworthy physical measurement. I will document and explain changes I personally make rather than claim the inherited application as code I wrote from scratch.
