# GStreamer Lab
![Gstreamer](https://github.com/user-attachments/assets/f10128f2-375e-41f2-8fed-d2ffc4576ba3)

This repository is focused on **learning GStreamer in depth** with the goal of becoming a Computer Vision engineer who understands video pipelines end-to-end, not just high-level frameworks:

- How **pipelines, elements, pads, caps, and buffers** work
- How to build pipelines in **C and Python**
- How **dynamic pipelines** work (adding/removing branches at runtime)
- How RTSP/RTP streaming works under the hood
- How all this connects to **NVIDIA DeepStream / TensorRT** later

> Goal: become the kind of Computer Vision engineer who understands the **video pipeline architecture end-to-end**, not only high-level tools.

---

## Learning Roadmap

### 0️⃣ Setup & Basic Tutorial

**Folder:** [`foundation/`](./foundation/)

Learn the fundamentals **Folder:** [`setup/`](./foundation/setup/):
- Install GStreamer dev packages (native & Docker)
- Verify `gst-launch-1.0` works
- Build and run first C program (`basic-tutorial-1.c`)
- Understand:
  - Pipeline creation with `gst_parse_launch()`
  - Element state management (NULL → PLAYING)
  - Message bus and error handling
  - Resource cleanup

**Files:**
- `install.sh` – automated GStreamer installation
- `basic-tutorial-1.c` – playbin example (plays video from URI)
- `Makefile` – build configuration
- `README.md` – complete tutorial with detailed explanations
  
Learn how Glib & Gobject matter and why use it **Folder:** [`Glib/`](./foundation/Glib/):
  - mini code show how implimant oop on c 
---
