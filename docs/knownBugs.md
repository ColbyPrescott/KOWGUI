# Known Bugs

I am already aware of these bugs and am working on fixing them. 
If you see anything that isn't on this list, feel free to open 
a new issue on the repository.

- `Keyboard` will not clear `std::cin` when opening. Typing 
    in the interactive terminal before opening the keyboard 
    will cause everything buffered to type instantly.
    <details>
    <summary>Goal</summary>

    > `std::cin.ignore()` is supposed to do this, but crashes 
    > the program instead. Find a different way to clear or 
    > ignore this buffer.
    </details>
- Multiple `Numpads` open at the same time will interfere with 
    each other.
    <details>
    <summary>Known fix</summary>

    > This was an oversight from adapting QWERTY `Keyboard` code. 
    > Should be fixed by moving variables into a `Data` node.
    </details>
- RoundedRectangle outlines can render weirdly in certain conditions. 
    <details>
    <summary>Details</summary>
    
    > - `Lines` seem to render off-center. Needs testing. <br>
    > - With highest radius, `Lines` don't render and leave a 
    > gap. <br>
    > - With high radius, `Circle` oulines will overlap. Use 
    > clipping areas to fix this one.
    </details>
- `Numpad` will not show the preceding zeros in the decimal.
    <details>
    <summary>Cause</summary>

    > The digits before and after the decimal are put in separate 
    > integer variables. The decimal loses its context of being 
    > a decimal and the zeros get cut off while formatting 
    > the text.
    </details>