import React, { useRef, useState, useEffect } from 'react';
import { motion, AnimatePresence } from 'framer-motion';
import ElasticSlider from './ElasticSlider';

function App() {
  const [showMain, setShowMain] = useState(false);
  const audioRef = useRef<HTMLAudioElement>(null);
  const [volume, setVolume] = useState(50);

  useEffect(() => {
    if (audioRef.current) {
      audioRef.current.volume = volume / 100;
      
      const handleEnded = () => {
        if (audioRef.current) {
          audioRef.current.currentTime = 0;
          audioRef.current.play();
        }
      };

      audioRef.current.addEventListener('ended', handleEnded);
      
      return () => {
        audioRef.current?.removeEventListener('ended', handleEnded);
      };
    }
  }, []);

  const handleClick = () => {
    setShowMain(true);
    if (audioRef.current) {
      audioRef.current.play().catch(error => {
        console.error('Audio playback failed:', error);
      });
    }
  };

  const handleVolumeChange = (newVolume: number) => {
    setVolume(newVolume);
    if (audioRef.current) {
      audioRef.current.volume = newVolume / 100;
    }
  };

  return (
    <div className="min-h-screen bg-gray-900 text-white">
      <AnimatePresence>
        {!showMain ? (
          <motion.div
            initial={{ opacity: 0 }}
            animate={{ opacity: 1 }}
            exit={{ opacity: 0 }}
            className="h-screen flex items-center justify-center"
          >
            <button
              onClick={handleClick}
              className="font-mono text-2xl hover:text-purple-400 transition-colors duration-300"
              style={{ fontFamily: 'Ubuntu Mono, monospace' }}
            >
              CLICK ME
            </button>
          </motion.div>
        ) : (
          <motion.div
            initial={{ opacity: 0 }}
            animate={{ opacity: 1 }}
            className="relative min-h-screen"
          >
            <motion.div
              className="fixed top-0 left-0 right-0 flex justify-center"
              initial={{ y: -100 }}
              animate={{ y: 0 }}
              transition={{
                type: "spring",
                stiffness: 100,
                damping: 20
              }}
            >
              <motion.div
                animate={{
                  rotate: [-2, 2, -2],
                }}
                transition={{
                  duration: 4,
                  ease: [0.44, 0, 0.56, 1],
                  repeat: Infinity,
                  times: [0, 0.5, 1]
                }}
                style={{
                  transformOrigin: "top center",
                  paddingTop: "0",
                  position: "relative",
                  userSelect: "none",
                  pointerEvents: "none"
                }}
              >
                <img
                  src="/src/asteroid.png"
                  alt="Asteroid"
                  className="w-[375px] h-[375px] object-contain"
                  draggable="false"
                />
                <motion.div
                  className="absolute left-1/2 -bottom-8 transform -translate-x-1/2 bg-black/80 px-4 py-2 rounded-full text-white text-sm whitespace-nowrap"
                  animate={{
                    rotate: [-2, 2, -2],
                  }}
                  transition={{
                    duration: 4,
                    ease: [0.44, 0, 0.56, 1],
                    repeat: Infinity,
                    times: [0, 0.5, 1]
                  }}
                  style={{
                    transformOrigin: "top center",
                  }}
                >
                  ...
                </motion.div>
              </motion.div>
            </motion.div>

            <motion.div
              className="fixed bottom-0 left-0 right-0 p-8 bg-gradient-to-t from-black/50 to-transparent"
              initial={{ y: 100 }}
              animate={{ y: 0 }}
              transition={{
                type: "spring",
                stiffness: 100,
                damping: 20
              }}
            >
              <div className="container mx-auto">
                <div className="flex justify-center">
                  <div className="w-full max-w-[250px]">
                    <ElasticSlider
                      defaultValue={volume}
                      maxValue={100}
                      isStepped
                      stepSize={1}
                      onChange={handleVolumeChange}
                    />
                  </div>
                </div>
              </div>
            </motion.div>
          </motion.div>
        )}
      </AnimatePresence>

      <audio
        ref={audioRef}
        src="/src/flove.mp3"
        loop
        preload="auto"
      />
    </div>
  );
}

export default App;