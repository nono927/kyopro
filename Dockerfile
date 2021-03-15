FROM ubuntu:20.10
RUN apt update && apt install -y \
    build-essential \
    git \
    cmake \
    python3 \
    pip \
    && apt clean \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /workspace
COPY ./requirements.txt .
RUN pip install -r requirements.txt
CMD ["/bin/bash"]