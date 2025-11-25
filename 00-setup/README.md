# GStreamer Lab - Docker Setup

## Overview

This directory contains a Docker-based setup for installing and running GStreamer in a clean, isolated environment. By using Docker, we ensure a fresh Ubuntu OS installation with GStreamer configured properly, avoiding conflicts with your host system's existing packages or dependencies.

## Why Docker?

Using Docker for GStreamer development provides several advantages:

- **Clean Environment**: Start with a fresh Ubuntu OS without affecting your host system
- **Isolation**: Keep GStreamer dependencies separate from your main system
- **Reproducibility**: Ensure consistent behavior across different development machines
- **Easy Reset**: If something breaks, simply rebuild the container
- **Version Control**: Lock specific versions of GStreamer and its plugins

## What's Included

This setup installs a complete GStreamer development environment with:

- **Core GStreamer Libraries**: Development headers and base libraries
- **Plugin Sets**:
  - `gstreamer1.0-plugins-base` - Essential plugins
  - `gstreamer1.0-plugins-good` - High-quality, well-tested plugins
  - `gstreamer1.0-plugins-bad` - Experimental or less stable plugins
  - `gstreamer1.0-plugins-ugly` - Plugins with licensing concerns
- **Additional Components**:
  - `gstreamer1.0-libav` - FFmpeg-based plugins for broad codec support
  - `gstreamer1.0-tools` - Command-line tools like `gst-launch-1.0`
  - `gstreamer1.0-x` - X11 video output support
  - `gstreamer1.0-alsa` - ALSA audio support
  - `gstreamer1.0-gl` - OpenGL support
  - `gstreamer1.0-gtk3` - GTK3 integration
  - `gstreamer1.0-qt5` - Qt5 integration
  - `gstreamer1.0-pulseaudio` - PulseAudio support

## File Structure

```
00-setup/
├── dockerfile           # Defines the Ubuntu-based container image
├── docker-compose.yml   # Configures container settings and X11 forwarding
├── install.sh          # GStreamer installation script
└── README.md           # This file
```

## Prerequisites

- Docker installed on your system
- Docker Compose installed (usually comes with Docker Desktop)
- X11 server running (for GUI applications)

## Usage

### 1. Build the Docker Image

Navigate to this directory and build the image:

```bash
cd 00-setup
docker build -t gstreamer-lab .
```

This will:
- Create an Ubuntu container (ubuntu:resolute-20251101)
- Set timezone to Africa/Casablanca
- Install all GStreamer packages and dependencies
- Verify the installation

### 2. Run the Container

#### Option A: Using Docker Compose (Recommended)

Run a test pipeline with video output:

```bash
docker-compose up
```

This will launch a GStreamer test pattern using `videotestsrc`.

#### Option B: Interactive Shell

To get an interactive bash shell inside the container:

```bash
docker run -it --rm \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  gstreamer-lab bash
```

#### Option C: Run with Custom Container Name

```bash
docker run -it --rm \
  --name gstreamer-lab \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
  gstreamer-lab bash
```

### 3. Test GStreamer Installation

Once inside the container, verify GStreamer is working:

```bash
# Check version
gst-launch-1.0 --version

# List available plugins
gst-inspect-1.0

# Test video output (opens a window with a test pattern)
gst-launch-1.0 videotestsrc ! autovideosink

# Test audio output
gst-launch-1.0 audiotestsrc ! autoaudiosink
```

### 4. Access Running Container

If your container is already running with the name from docker-compose (`gst-lab`):

```bash
docker exec -it gst-lab bash
```

## Troubleshooting

### X11 Display Issues

If you can't see video output:

1. Allow X11 connections from Docker:
   ```bash
   xhost +local:docker
   ```

2. Verify DISPLAY variable is set:
   ```bash
   echo $DISPLAY
   ```

3. Check X11 socket exists:
   ```bash
   ls -la /tmp/.X11-unix
   ```

### Container Not Found

If you see "No such container: gstreamer-lab":

- The container might not be running. Use `docker ps` to check running containers
- The container name in docker-compose.yml is `gst-lab`, not `gstreamer-lab`
- Use the correct name: `docker exec -it gst-lab bash`

### Permission Denied on X11 Socket

Run on your host machine:

```bash
xhost +local:root
```

## Configuration

### Timezone

The default timezone is set to `Africa/Casablanca`. To change it:

1. Edit `dockerfile` and change the `TZ` environment variable
2. Edit `install.sh` and update the timezone path in line 15

### Display Settings

X11 display forwarding is configured in `docker-compose.yml`:
- `DISPLAY` environment variable is passed from host
- `/tmp/.X11-unix` is mounted for X11 socket access

## Development Workflow

1. **Build once**: Create the image with all dependencies
2. **Run interactively**: Launch container with bash shell
3. **Experiment**: Test GStreamer pipelines and commands
4. **Iterate**: Make changes and test without affecting host system
5. **Rebuild**: If needed, rebuild image with updated dependencies

## Next Steps

After setting up your environment, you can:

- Explore GStreamer pipelines
- Build custom video/audio processing applications
- Test different plugin combinations
- Develop GStreamer plugins
- Learn multimedia processing concepts

## References

- [Official GStreamer Documentation](https://gstreamer.freedesktop.org/documentation/)
- [Installing GStreamer on Linux](https://gstreamer.freedesktop.org/documentation/installing/on-linux.html)
- [GStreamer Tutorials](https://gstreamer.freedesktop.org/documentation/tutorials/)

---

**Base Image**: Ubuntu Resolute (20251101)  
**GStreamer Version**: 1.0 (latest from Ubuntu repositories)  
**Timezone**: Africa/Casablanca

