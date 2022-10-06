import moviepy
import moviepy.editor
video =moviepy.editor.VideoFileClip("")
audio= video.audio
audio.write_audiofile('new_audio.mp')