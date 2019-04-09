function [y1, y2] = fooSlow(x1, x2, x3)
    y1 = x1 + x2;
    y2 = sum(sum(x3));
end
