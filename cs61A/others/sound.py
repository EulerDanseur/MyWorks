from wave import open
from struct import Struct
from math import floor

frame_rate = 11025

def encode(x):
    i = int(16384 * x)
    return Struct('h').pack(i)

def play(sampler, name = 'sound.wav', seconds = 2):
    out = open(name, 'wb')
    out.setnchannels(1)
    out.setsampwidth(2)
    out.setframerate(frame_rate)
    for i in range(frame_rate * seconds):
        out.writeframesraw(encode(sampler(i)))
    out.close()
    
def tri(freq, amp = 0.3):
    period = frame_rate // freq
    def sampler(t):
        saw_wave = t / period - floor(t / period + 0.5)
        tri_wave = 2 * abs(2 * saw_wave) - 1
        return amp * tri_wave
    return sampler

def both(sampler1, sampler2):
    return lambda t: (sampler1(t) + sampler2(t))

def note(f, start, end):
    def sampler(t):
        if t < start:
            return 0
        elif t > end:
            return 0
        else:
            return f(t)
    return sampler

c_freq = 261.63
d_freq = 293.66
e_freq = 329.63
f_freq = 349.23
g_freq = 392.00
a_freq = 440.00
b_freq = 493.88