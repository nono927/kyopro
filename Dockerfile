FROM ubuntu:20.10
RUN apt update
RUN apt install -y \
    build-essential \
    git \
    python3 \
    pip 
WORKDIR /workspace
COPY ./requirements.txt .
RUN pip install -r requirements.txt
CMD ["/bin/bash"]