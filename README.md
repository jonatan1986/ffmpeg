# ffmpeg
impotrant notes:
1)As much as i tried, i didnt manage to run ffmpeg, and get the result you presented  in the file:
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_start: 5.3053
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_duration: 2.05205
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_end: 7.35735
[freezedetect @ 0x7faf71100a00] lavfi.freezedetect.freeze_start: 16.78345    
...

after running: "ffmpeg -i freeze_frame_input_b.mp4 -vf "freezedetect=n=-0.003dB" -map 0:v:0 -f null -"
I got a result which shows only : "freeze_start"(output of the command pasted,follows the explanation)
I was trying about hour and a half to work it out - didnt manage to
I descided to create files which have the same output - parse them and create json file.
I managed to parse the files, but when i tried to print them to json file , I had a problem:
I arranged all the data such as : start and end times,longest valid periods, total aggregated persiods 
into three vector, and in order to print them to json i had to parse all the 3 at the same time,
it just didnt compile.
I searched in google and saw there is a library of boost for iterating more than one data structure
it said I have to use boost librarym somthing with zip. i didnt have any time left to install it
i wrote the task in c++. i know that python has a library for that(zip).















output of  "ffmpeg -i freeze_frame_input_b.mp4 -vf "freezedetect=n=-0.003dB" -map 0:v:0 -f null -"

ffmpeg version 4.3-2~18.04.york0 Copyright (c) 2000-2020 the FFmpeg developers
  built with gcc 7 (Ubuntu 7.5.0-3ubuntu1~18.04)
  configuration: --prefix=/usr --extra-version='2~18.04.york0' --toolchain=hardened --libdir=/usr/lib/x86_64-linux-gnu --incdir=/usr/include/x86_64-linux-gnu --arch=amd64 --enable-gpl --disable-stripping --enable-avresample --disable-filter=resample --enable-gnutls --enable-ladspa --enable-libaom --enable-libass --enable-libbluray --enable-libbs2b --enable-libcaca --enable-libcdio --enable-libcodec2 --enable-libflite --enable-libfontconfig --enable-libfreetype --enable-libfribidi --enable-libgme --enable-libgsm --enable-libjack --enable-libmp3lame --enable-libmysofa --enable-libopenjpeg --enable-libopenmpt --enable-libopus --enable-libpulse --enable-librabbitmq --enable-librsvg --enable-librubberband --enable-libshine --enable-libsnappy --enable-libsoxr --enable-libspeex --enable-libsrt --enable-libssh --enable-libtheora --enable-libtwolame --enable-libvidstab --enable-libvorbis --enable-libvpx --enable-libwavpack --enable-libwebp --enable-libx265 --enable-libxml2 --enable-libxvid --enable-libzmq --enable-libzvbi --enable-lv2 --enable-omx --enable-openal --enable-opencl --enable-opengl --enable-sdl2 --enable-pocketsphinx --enable-libdc1394 --enable-libdrm --enable-libiec61883 --enable-chromaprint --enable-frei0r --enable-libx264 --enable-shared
  libavutil      56. 51.100 / 56. 51.100
  libavcodec     58. 91.100 / 58. 91.100
  libavformat    58. 45.100 / 58. 45.100
  libavdevice    58. 10.100 / 58. 10.100
  libavfilter     7. 85.100 /  7. 85.100
  libavresample   4.  0.  0 /  4.  0.  0
  libswscale      5.  7.100 /  5.  7.100
  libswresample   3.  7.100 /  3.  7.100
  libpostproc    55.  7.100 / 55.  7.100
Input #0, mov,mp4,m4a,3gp,3g2,mj2, from 'freeze_frame_input_b.mp4':
  Metadata:
    major_brand     : mp42
    minor_version   : 1
    compatible_brands: mp41mp42isom
    creation_time   : 2019-12-23T23:05:27.000000Z
  Duration: 00:00:29.06, start: 0.000000, bitrate: 7029 kb/s
    Stream #0:0(eng): Audio: aac (LC) (mp4a / 0x6134706D), 48000 Hz, stereo, fltp, 41 kb/s (default)
    Metadata:
      creation_time   : 2019-12-23T23:05:27.000000Z
      handler_name    : Core Media Audio
    Stream #0:1(und): Video: h264 (High) (avc1 / 0x31637661), yuv420p(tv, bt709, progressive), 960x540 [SAR 1:1 DAR 16:9], 6947 kb/s, 59.94 fps, 59.94 tbr, 60k tbn, 120k tbc (default)
    Metadata:
      creation_time   : 2019-12-23T23:05:27.000000Z
      handler_name    : Core Media Video
Stream mapping:
  Stream #0:1 -> #0:0 (h264 (native) -> wrapped_avframe (native))
Press [q] to stop, [?] for help
Output #0, null, to 'pipe:':
  Metadata:
    major_brand     : mp42
    minor_version   : 1
    compatible_brands: mp41mp42isom
    encoder         : Lavf58.45.100
    Stream #0:0(und): Video: wrapped_avframe, yuv420p, 960x540 [SAR 1:1 DAR 16:9], q=2-31, 200 kb/s, 59.94 fps, 59.94 tbn, 59.94 tbc (default)
    Metadata:
      creation_time   : 2019-12-23T23:05:27.000000Z
      handler_name    : Core Media Video
      encoder         : Lavc58.91.100 wrapped_avframe
[freezedetect @ 0x556e75b38380] lavfi.freezedetect.freeze_start: 0
frame= 1742 fps=376 q=-0.0 Lsize=N/A time=00:00:29.06 bitrate=N/A speed=6.28x    
video:912kB audio:0kB subtitle:0kB other streams:0kB global headers:0kB muxing overhead: unknown

