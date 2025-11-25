# GStreamer Lab
<img width="1344" height="768" alt="Gstreamer" src="https://github.com/user-attachments/assets/09b90766-ee89-432f-b9ea-d13f6bfc61bd" />

This repo is my personal playground to **learn GStreamer deeply** – not just to use DeepStream, but to really understand:

- How **pipelines, elements, pads, caps, and buffers** work
- How to build pipelines in **C and Python**
- How **dynamic pipelines** work (adding/removing branches at runtime)
- How RTSP/RTP streaming works under the hood
- How all this connects to **NVIDIA DeepStream / TensorRT** later

> Goal: become the kind of Computer Vision engineer who understands the **video pipeline architecture end-to-end**, not only high-level tools.

---

## Learning Roadmap

### 0️⃣ Setup

- Install GStreamer dev packages
- Verify `gst-launch-1.0` works
- Verify C and Python bindings

Folder: [`00-setup/`](./00-setup/)

---

### 1️⃣ CLI Pipelines (`gst-launch-1.0`)

- Build simple pipelines:
  - `videotestsrc ! autovideosink`
  - `videotestsrc ! videoconvert ! xvimagesink`
  - Play a file: `filesrc ! decodebin ! autovideosink`
- Learn:
  - what a **pipeline** is
  - what **elements** are
  - what **pads** and **caps** are (just from CLI for now)

Folder: [`01-cli-basics/`](./01-cli-basics/)

---

### 2️⃣ Pipeline Fundamentals (Theory + Notes)

- Elements, source vs sink
- Pads: static vs sometimes pads
- Caps negotiation
- State machine: NULL → READY → PAUSED → PLAYING
- Buffer flow and timestamps (high level)

Folder: [`02-pipeline-fundamentals/`](./02-pipeline-fundamentals/)

---

### 3️⃣ C: Hello GStreamer

- Minimal C program to:
  - init GStreamer
  - create a `videotestsrc ! autovideosink` pipeline
  - set to PLAYING
  - run main loop
- Build with a simple `Makefile`.

Folder: [`03-c-hello-pipeline/`](./03-c-hello-pipeline/)

---

### 4️⃣ Python: Hello GStreamer

- Same thing as C but using:
  - `gi.repository.Gst`
  - `gi.repository.GObject`

Folder: [`04-python-hello-pipeline/`](./04-python-hello-pipeline/)

---

### 5️⃣ Dynamic Pipelines

- Use `tee` to split a stream into 2 branches
- Dynamically add/remove a branch at runtime
- Understand **pad linking/unlinking** at runtime

Folder: [`05-dynamic-pipelines/`](./05-dynamic-pipelines/)

---

### 6️⃣ Custom Bins and Ghost Pads

- Group elements into a **bin**
- Expose ghost pads
- Understand how DeepStream builds complex elements from simple ones

Folder: [`06-custom-bins-and-ghostpads/`](./06-custom-bins-and-ghostpads/)

---

### 7️⃣ RTSP & Networking

- Receive RTSP with `rtspsrc`
- De-pay, decode, display
- Play with latency parameters

Folder: [`07-rtsp-and-networking/`](./07-rtsp-and-networking/)

---

### 8️⃣ Encoding & Files

- Read video from file, transcode, and write to disk

Folder: [`08-filesrc-and-encoding/`](./08-filesrc-and-encoding/)

---

### 9️⃣ Plugin Architecture (Theory)

- How plugins are discovered
- Plugin registry
- Element factories
- Versioning

Folder: [`09-plugins-architecture/`](./09-plugins-architecture/)

---

### 🔟 DeepStream Bridge

- Map GStreamer concepts to DeepStream:
  - DeepStream elements vs normal GStreamer elements
  - nvstreammux, nvinfer, nvtracker as GStreamer plugins
  - why understanding GStreamer makes you faster with DeepStream

Folder: [`10-deepstream-bridge/`](./10-deepstream-bridge/)

---

## How to Use This Repo

Each folder has:

- `notes.md` – short theory + diagrams
- `*.c` / `*.py` – runnable examples
- `Makefile` or simple command to run

This repo is **for learning**, not for production – but the skills here are what I use later in real systems.
