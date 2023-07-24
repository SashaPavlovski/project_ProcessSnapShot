# ProcessSnapShot

## Overview

ProcessSnapShot is a command-line utility that captures and analyzes snapshots of running processes on a system. It allows users to monitor system resource usage, track process behavior over time, and identify potential performance bottlenecks.

## Features

- **Process Snapshot**: Capture detailed information about running processes, including CPU and memory usage.
- **Interval Monitoring**: Set intervals to take periodic snapshots for continuous process monitoring.
- **Resource Analysis**: Analyze captured snapshots to identify resource-intensive processes.
- **Command-line Interface**: User-friendly CLI for easy interaction and script integration.

## Technologies Used

- Language: c


## Getting Started

To use ProcessSnapShot, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/SashaPavlovski/project_ProcessSnapShot.git
   ```

2. Install dependencies:
   ```bash
   pip install psutil
   ```

3. Run the application:
   ```bash
   python process_snapshot.py --interval 5 --duration 60
   ```
   This will start capturing snapshots every 5 seconds for a duration of 60 seconds.

4. Analyze the output:
   After the process is complete, the captured snapshots will be available for analysis.
