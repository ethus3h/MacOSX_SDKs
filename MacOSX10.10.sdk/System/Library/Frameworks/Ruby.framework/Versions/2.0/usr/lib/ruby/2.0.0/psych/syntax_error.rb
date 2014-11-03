module Psych
  class Error < RuntimeError
  end

  class SyntaxError < Error
    attr_reader :file, :line, :column, :offset, :problem, :context

    def initialize file, line, col, offset, problem, context
      err      = [problem, context].compact.join ' '
      filename = file || '<unknown>'
      message  = "(%s): %s at line %d column %d" % [filename, err, line, col]

      @file    = file
      @line    = line
      @column  = col
      @offset  = offset
      @problem = problem
      @context = context
      super(message)
    end
  end
end
