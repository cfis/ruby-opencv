module Cv
	class Mat
		def to_s
			"<#{self.class.name}:#{self.rows}x#{self.cols},type=#{type},channel=#{self.channels}>"
		end
	end
end
